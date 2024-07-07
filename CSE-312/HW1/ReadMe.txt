This file contains information about how to run the OS in virtualbox.

Required packages:
	g++
	binutils
	libc6-dev-i386
	grub-legacy
	xorriso
	grub2-common
	grub-pc

	Install virtualbox (my version is: Version 7.0.18 r162988 (Qt5.15.2))

How to run:
	1. In project directory, execute "make mykernel.iso"
	2. Open virtualbox and create new virtual machine.
	3. Select "mykernel.iso" in the ISO Image section.
	4. Select the Type as "Other"
	5. Select the Version as "Other/Unknown"
	6. Click next until Virtual Hard Disk part
	7. Click Do Not Add a Virtual Hard Disk
	8. Click next and finish.





