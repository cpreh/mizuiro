#!/bin/bash

if [[ $1 == 'run' ]]; then
	shift
	prettify_includes.py --reserved-prefix mizuiro --external-begin 'mizuiro/detail/external_begin.hpp' --external-end 'mizuiro/detail/external_end.hpp' "$@" 2>>/tmp/prettify_errors
else
	find examples include test \( \( -name '*.hpp' -o -name '*.cpp' \) \) | xargs $0 run
fi
