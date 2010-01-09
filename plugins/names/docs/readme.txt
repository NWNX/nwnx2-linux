This is an example of persistent storage for names.

ax_dynamic_names.sql - MySQL table definition
vir_dnames_inc.nss - a sample include file
vir_dnames_inc.erf - include with dependencies

You'll have to modify these files to integrate it into your PW.
The include relies on unique character IDs, so you need to have it on your PW.
GetPCId returns the unique PC ID. You can replace this function with whatever you have in your PW's systems.