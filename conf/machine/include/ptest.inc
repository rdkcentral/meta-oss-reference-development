# Global: Enable ptest framework for all packages
PTEST_ENABLED = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', '1', '', d)}"

# Image content: What to include in the image (when ptest enabled)
EXTRA_IMAGE_FEATURES:append = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' ptest-pkgs', '', d)}"

# For the following recipes enabling ptest results in failure so removed them will work on enabling in upcoming releases
IMAGE_INSTALL:remove = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' gdbm-ptest pango-ptest bluez5-ptest findutils-ptest lttng-tools-ptest', '', d)}"
PTEST_ENABLED:pn-bluez5 = "0"

# License policy: What licenses are acceptable in this build
LICENSE_FLAGS_ACCEPTED:append = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' GPL-3.0-only GPL-3.0-or-later', '', d)}"
INCOMPATIBLE_LICENSE:remove = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' GPL-3.0-only LGPL-3.0-only LGPL-3.0-or-later GPL-3.0-or-later', '', d)}"

# To supress compilation error in glibc-tests when ptest is enabled
CFLAGS:append:pn-glibc-tests = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' -Wno-error=format-overflow', '', d)}"

# Version preferences, lower versions doesn't have ptest support
PREFERRED_VERSION_gmp = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', '6.2.1', '', d)}"
PREFERRED_VERSION_coreutils = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', '9.0', '', d)}"
PREFERRED_VERSION_m4 = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', '1.4.19', '', d)}"
BBMASK:append = "${@bb.utils.contains('DISTRO_FEATURES', 'ptest', ' meta-rdk-oss-reference/recipes-gplv2/gettext/gettext_0.16.1.bb ', '', d)}"

# Adding components for which ptest support is newly added
PTESTS_FAST:append = " alsa-lib-ptest \
                libatomic-ops-ptest \
                libcheck-ptest \
                xz-ptest \
                libcap-ptest \
                kbd-ptest \
                file-ptest \
                zstd-ptest \
                attr-ptest \
                grep-ptest \
                curl-ptest \
                make-ptest \
                libpcap-ptest \
                apr-util-ptest \
                libxslt-ptest \
                lz4-ptest \
                gmp-ptest \
                opkg-utils-ptest \
              "
