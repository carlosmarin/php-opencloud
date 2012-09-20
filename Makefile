# builds the distribution archives and cleans up

BUILD=$(shell expr `cat scripts/BUILD` + 1)
VERSION=$(shell grep "'RAXSDK_VERSION'" lib/globals.inc | sed -e 's/[^0-9\.]//g')
LIBRARY=php-opencloud-$(VERSION).$(BUILD)
ARCHIVE=$(LIBRARY).tar
TARFILE=$(ARCHIVE).gz
ZIPFILE=$(LIBRARY).zip
FILES=README.md COPYING lib docs samples tests

all: $(TARFILE) $(ZIPFILE)
	echo $(BUILD) > scripts/BUILD

$(TARFILE): $(ARCHIVE)
	gzip $(ARCHIVE)

$(ARCHIVE):
	tar cvf $(ARCHIVE) $(FILES)

$(ZIPFILE):
	zip $(ZIPFILE) $(FILES)

clean:
	rm *.gz *.zip