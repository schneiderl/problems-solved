from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
import re


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


def do_simple_search(name):
    url_root = 'https://xtools.wmflabs.org/articleinfo/en.wikipedia.org/{}'
    response = simple_get(url_root.format(name))
    if response is not None:
        html = BeautifulSoup(response, 'html.parser')
        hit_link = [a for a in html.select(
            'a') if a['href'].find('latest-60') > -1]
    if(len(hit_link) > 0):
        link_text = hit_link[0].text.replace(',', '')
        try:
            return int(link_text)
        except:
            log_error('couldnt parse' + link_text + "as an int.")
    return None


def get_canonical_url(resp):
    html = BeautifulSoup(resp, 'html.parser')
    links_list = html.select('link')
    url = ""
    for link in links_list:
        if(link['rel'][0] == 'canonical'):
            url = link['href']
    return url


def was_page_redirected(current_url):
    if current_url.find("index.php?search=") > -1:
        return False
    else:
        return True


def do_wiki_search(name):
    wiki_search_url = "https://en.wikipedia.org/w/index.php?search={}"
    name = name.replace(" ", "+")
    response = simple_get(wiki_search_url.format(name))

    current_url = get_canonical_url(response)
    if was_page_redirected(current_url):
        # then we are on the wikipedia page
        name = current_url.replace(
            "https://en.wikipedia.org/wiki/", "").strip()
        return(do_simple_search(name))
    else:
        log_error("Couldn't find any results for {}".format(name.replace("+"," ")))
        # then we are on the wikipedia search page
        #TODO: Perform a search for possible mathematicians of the result list


def get_score(name):
    score = do_simple_search(name)
    if score is None:
        score = do_wiki_search(name)
    if score is None:
        print("couldnt find any information about {}".format(name))
        return None
    return score


def get_names():
    raw_html = simple_get('http://www.fabpedigree.com/james/mathmen.htm')
    html = BeautifulSoup(raw_html, 'html.parser')
    names = set()
    for li in html.select('li'):
        for name in li.text.split('\n'):
            if len(name) > 0:
                names.add(re.sub(r"(\s|^)[A-Z]\.", "", name.strip()))
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
