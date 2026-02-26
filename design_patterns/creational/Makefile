PATTERNS = singleton builder factory_method abstract_factory prototype

.PHONY: all run clean $(PATTERNS)

all: $(PATTERNS)

$(PATTERNS):
	$(MAKE) -C $@

run:
	@for p in $(PATTERNS); do \
		echo ""; \
		echo "=== $$p ==="; \
		$(MAKE) -C $$p run --no-print-directory; \
	done

clean:
	@for p in $(PATTERNS); do \
		$(MAKE) -C $$p clean --no-print-directory; \
	done
