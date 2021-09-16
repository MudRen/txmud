// Room: /d/shaolin/tongren3.c

inherit ROOM;
inherit __DIR__"t_zhen";

int query_stage() { return 2; }
string query_out() { return "west"; }
string query_out_file() { return __DIR__"tongren4"; }

void create()
{
	set("short", "É½¶´");
	set("long", @LONG
ÕâÀïÊÇÒ»¸ö»è°µµÄÉ½¶´£¬É½¶´±ÚÉÏÓĞ¼¸¸ùĞÜĞÜÈ¼ÉÕµÄ»ğ°Ñ£¬
Ó­ÃæµÄÊ¯°åÉÏÇ¶×ÅÒ»¿éÍ­ÅÆÓ³×Å»ğ¹âÉÁÉÁ·¢ÁÁ£¬ÉÏĞ´×Å

	[1;33m¡ºÍ­ ÈË Õó¡»µÚ ¶ş ¹Ø[2;37;0m

LONG
	);

	setup();
}

int valid_leave(object who,string dir)
{
	mapping dirs = (["north":"south","south":"north","east":"west","west":"east"]);
	if(dir == dirs[query_out()])
		return notify_fail("\nÄãÖ»Ìıµ½Ò»Õó¡°ß´¸Á¡±ÂÒÏì£¬Ò»¹ÉÇ¿¾¢µÄÒõ·ç°ÑÄãÍÆÁË»ØÀ´¡£\n\n");

	return 1;
}
