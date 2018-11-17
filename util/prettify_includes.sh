#!/bin/bash

if [[ $1 == 'run' ]]; then
	shift
	prettify_includes.py --reserved-prefix fcppt --reserved-prefix mizuiro "$@" 2>>/tmp/prettify_errors
else
	find examples include test \( \( -name '*.hpp' -o -name '*.cpp' \) \) | xargs $0 run
fi
