include ports/pcre.inc

PCRE_TBZ      = $(PCRE).tar.bz2
PCRE_SIG      = $(PCRE_TBZ).sig
PCRE_BASE_URL = ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre
PCRE_URL      = $(PCRE_BASE_URL)/$(PCRE_TBZ)
PCRE_URL_SIG  = $(PCRE_BASE_URL)/$(PCRE_SIG)
PCRE_KEY      = ph10@cam.ac.uk

#
# Interface to top-level prepare Makefile
#
PORTS += $(PCRE)

prepare-pcre: $(CONTRIB_DIR)/$(PCRE) include/pcre

$(CONTRIB_DIR)/$(PCRE): clean-pcre

#
# Port-specific local rules
#
$(DOWNLOAD_DIR)/$(PCRE_TBZ):
	$(VERBOSE)wget -c -P $(DOWNLOAD_DIR) $(PCRE_URL) && touch $@

$(DOWNLOAD_DIR)/$(PCRE_SIG):
	$(VERBOSE)wget -c -P $(DOWNLOAD_DIR) $(PCRE_URL_SIG) && touch $@

$(DOWNLOAD_DIR)/$(PCRE_TBZ).verified: $(DOWNLOAD_DIR)/$(PCRE_TBZ) \
                                      $(DOWNLOAD_DIR)/$(PCRE_SIG)
	$(VERBOSE)$(SIGVERIFIER) $(DOWNLOAD_DIR)/$(PCRE_TBZ) $(DOWNLOAD_DIR)/$(PCRE_SIG) $(PCRE_KEY)
	$(VERBOSE)touch $@

$(CONTRIB_DIR)/$(PCRE): $(DOWNLOAD_DIR)/$(PCRE_TBZ)
	$(VERBOSE)tar xfj $(<:.verified=) -C $(CONTRIB_DIR) && touch $@

include/pcre:
	$(VERBOSE)mkdir -p $@
	$(VERBOSE)ln -sf ../../src/lib/pcre/include/pcre.h include/pcre

clean-pcre:
	$(VERBOSE)rm -rf $(CONTRIB_DIR)/$(PCRE)
	$(VERBOSE)rm -rf include/pcre
