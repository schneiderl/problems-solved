from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup

def get_mathematicians_ranking():
	names = get_names()
	results = []
	for name in names:
		score = get_score(name)
		if score is not None:
			results.append((score, name))
	results.sort()
	results.reverse()
	for pv, mathematician in results:
		print("{} had {} pageviews in the last 60 days.".format(mathematician, pv))

def get_score(name):
	url_root = 'https://xtools.wmflabs.org/articleinfo/en.wikipedia.org/{}'
	response = simple_get(url_root.format(name))
	if response is not None:
		html = BeautifulSoup(response, 'html.parser')
		hit_link = [a for a in html.select('a') if a['href'].find('latest-60') > -1]
	if(len(hit_link)>0):
		link_text = hit_link[0].text.replace(',','')
		try:
			return int(link_text)
		except:
			log_error('couldnt parse' + link_text + "as an int.")

	log_error("No pageviews found for " + name)
	return None


def get_names():
    raw_html = simple_get('http://www.fabpedigree.com/james/mathmen.htm')
    html = BeautifulSoup(raw_html, 'html.parser')
    names = set()
    for li in html.select('li'):
        for name in li.text.split('\n'):
            if len(name) > 0:
                names.add(name.strip())
    return list(names)


def simple_get(url):
    try:
        with closing(get(url, stream=True)) as resp:
            if is_good_response(resp):
                return resp.content
            else:
                return None

    except RequestException as e:
        log_error('Error during requests to {0} : {1}'.format(url, str(e)))
        return None


def is_good_response(resp):
    content_type = resp.headers['Content-Type'].lower()
    return (resp.status_code == 200
            and content_type is not None
            and content_type.find('html') > -1)


def log_error(e):
    print(e)
