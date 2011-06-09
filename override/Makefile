OVERRIDES = netoverride openoverride bindoverride

.PHONY: $(OVERRIDES)

all: $(OVERRIDES)

clean:
	for x in $(OVERRIDES); do \
		make -C $$x clean; done

$(OVERRIDES):
	make -C $@ all
