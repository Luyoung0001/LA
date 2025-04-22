gallery_dir := "./gallery"

manual:
	typst compile manual.typ

LA:
	typst compile --root . LA.typ

gallery:
	for f in "{{gallery_dir}}"/*.typ; do typst c --root . "$f" "${f%typ}png"; done
