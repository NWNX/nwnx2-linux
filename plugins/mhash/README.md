# nwnx_mhash

This is a plugin giving access to all hash and HMAC functions mhash(3) provides on your system.
To compile, you obviously need to have libmhash-dev installed.

For a full list of supported algorithms on your system, check the server log after loading the plugin.

Usually, it looks something like this (do not assume all these are available on your system, CHECK):

	Supported algorithms:
	  CRC32           (hmac: 0, result length: 8)
	  MD5             (hmac: 1, result length: 32)
	  SHA1            (hmac: 1, result length: 40)
	  HAVAL256        (hmac: 1, result length: 64)
	  RIPEMD160       (hmac: 1, result length: 40)
	  TIGER           (hmac: 1, result length: 48)
	  GOST            (hmac: 0, result length: 64)
	  CRC32B          (hmac: 0, result length: 8)
	  HAVAL224        (hmac: 1, result length: 56)
	  HAVAL192        (hmac: 1, result length: 48)
	  HAVAL160        (hmac: 1, result length: 40)
	  HAVAL128        (hmac: 1, result length: 32)
	  TIGER128        (hmac: 1, result length: 32)
	  TIGER160        (hmac: 1, result length: 40)
	  MD4             (hmac: 1, result length: 32)
	  SHA256          (hmac: 1, result length: 64)
	  ADLER32         (hmac: 0, result length: 8)
	  SHA224          (hmac: 1, result length: 56)
	  SHA512          (hmac: 1, result length: 128)
	  SHA384          (hmac: 1, result length: 96)
	  WHIRLPOOL       (hmac: 1, result length: 128)
	  RIPEMD128       (hmac: 1, result length: 32)
	  RIPEMD256       (hmac: 1, result length: 64)
	  RIPEMD320       (hmac: 1, result length: 80)
	  SNEFRU128       (hmac: 1, result length: 32)
	  SNEFRU256       (hmac: 1, result length: 64)

See the included ```nwnx_mhash.nss``` for usage examples. When saving/editing the given include,
make sure you do it with a windows-1252 (or ISO-8859-15) encoding; something that does not mangle
the ```¬``` character used as a delimiter.

Any usage or library errors are printed to the plugin log at ```logs.0/nwnx_mhash.txt```.

Setting debuglevel to 2 will provide full output of all calls, like so (in ```nwnx2.ini```):

	[MHASH]
	debuglevel=2
