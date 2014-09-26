Name:           wayland-kms
Version:        1.2.0
Release:	0
License:	MIT
Summary:	wayland-kms library
Source:       %{name}-%{version}.tar.gz
Source1001:     wayland-kms.manifest
BuildRequires:  automake
BuildRequires:  libtool
BuildRequires:  pkgconfig(libkms)
BuildRequires:  pkgconfig(libdrm) >= 2.4.24
BuildRequires:  pkgconfig(libudev) > 150
BuildRequires:  pkgconfig(wayland-client)
BuildRequires:  pkgconfig(wayland-server)

%description
wayland-kms

%package devel
Summary:	wayland-kms library (devel)
Group:		Development/Libraries
Requires:	%{name} = %{version}-%{release}

%description devel
wayland-kms development files

%prep
%setup

%build
autoreconf -vif
%configure
make

%install
%make_install

%post   -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
#%manifest %{name}.manifest
%defattr(-,root,root)
%{_libdir}/libwayland-kms.so*

%files devel
%{_libdir}/pkgconfig/wayland-kms.pc
%{_includedir}/wayland-kms.h
%{_includedir}/wayland-kms-client-protocol.h
%{_includedir}/wayland-kms-server-protocol.h
