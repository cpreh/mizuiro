#!/usr/bin/env bash

ARGS=(--library mizuiro --library fcppt)

find examples include test \( \( -name '*.hpp' -o -name '*.cpp' \) \) -exec update_headers.sh '{}' "${ARGS[@]}" \;
