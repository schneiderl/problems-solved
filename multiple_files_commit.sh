for page in $(git diff --name-only); do
  git add "${page}" # Add the page to the index
  git commit -m "$(basename -- $page .md): commit message here" # Commit the page
done
