DISTRO_VERSION = "2.0"
DISTRO_NAME="RDK (A Yocto Project based Distro)"
TARGET_VENDOR = "-rdk"
# The Artifactory for OSS IPK has to be added later
RDK_ARTIFACTS_BASE_URL ?= ""
CMF_GIT_ROOT ?= "git://code.rdkcentral.com/r"
CMF_GIT_PROTOCOL ?= "https"
CMF_GIT_MASTER_BRANCH ?= "master"

# The Github URL is setting to RDKCentral. This may have to modify in case of any change in the settings
RDKE_GITHUB_ROOT ?= "git://git@github.com/rdkcentral"
RDKE_GITHUB_PROTOCOL ?= "ssh"
RDKE_GITHUB_BRANCH ?= "nobranch=1"
RDKE_GITHUB_SRC_URI_SUFFIX ?= "protocol=${RDKE_GITHUB_PROTOCOL};${RDKE_GITHUB_BRANCH}"

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

OSS_LAYER_ARCH = "${MACHINE}-oss"
PACKAGE_EXTRA_ARCHS:append = " ${OSS_LAYER_ARCH}"

# Disable layer consumption for oss layer
USER_CLASSES:remove = "base-deps-resolver"

include package_revisions_oss.inc
