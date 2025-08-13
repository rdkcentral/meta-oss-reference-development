DISTRO_VERSION = "2.0"
DISTRO_NAME="RDK (A Yocto Project based Distro)"
TARGET_VENDOR = "-rdk"

#Mirror configurations
PREMIRRORS ?= "\
bzr://.*/.*   http://96.118.132.221/pub/sources/ \n \
cvs://.*/.*   http://96.118.132.221/pub/sources/ \n \
git://.*/.*   http://96.118.132.221/pub/sources/ \n \
hg://.*/.*    http://96.118.132.221/pub/sources/ \n \
osc://.*/.*   http://96.118.132.221/pub/sources/ \n \
p4://.*/.*    http://96.118.132.221/pub/sources/ \n \
svn://.*/.*   http://96.118.132.221/pub/sources/ \n"

MIRRORS =+ "\
ftp://.*/.*      http://96.118.132.221/pub/sources/ \n \
http://.*/.*     http://96.118.132.221/pub/sources/ \n \
https://.*/.*    http://96.118.132.221/pub/sources/ \n"


BB_DANGLINGAPPENDS_WARNONLY = "true"

TCLIBCAPPEND = ""

DISTRO_FEATURES_BACKFILL_CONSIDERED += "pulseaudio"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "gobject-introspection-data"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "ldconfig"

DISTRO_FEATURES:append = " gobject-introspection-data"

PREFERRED_PROVIDER_virtual/kernel = ""

# Disable layer consumption for oss layer
USER_CLASSES:remove = "base-deps-resolver"
