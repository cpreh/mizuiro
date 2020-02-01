#!/usr/bin/env bash

LIBS=(--library mizuiro --library fcppt)
DIRS=(examples include test)

prettify_includes "${LIBS[@]}" "${DIRS[@]}"
