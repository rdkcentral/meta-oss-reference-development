DISTRO_VERSION = "2.0"
DISTRO_NAME = "RDK (A Yocto Project based Distro)"

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

require ${@bb.utils.contains('LAYERSERIES_CORENAMES', 'wrynose', 'conf/machine/include/oss-feature-optouts-wrynose.inc', 'conf/machine/include/oss-feature-optouts-legacy.inc', d)}

DISTRO_FEATURES:append = " gobject-introspection-data"

PREFERRED_PROVIDER_virtual/kernel = ""
