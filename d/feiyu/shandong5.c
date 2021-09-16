// Room: /wiz/louth/a/shandong5.c

inherit ROOM;

void create()
{
	set("short", "É½¶´¿Ú");
	set("long", @LONG
ÕâÀïÊÇ¿í³¨¸ÉÔïµÄ´óÉ½¶´£¬ËÄÖÜµÄÊ¯±Ú(wall)ÔäµÄÊ®·ÖÆ½Õû£¬
ÉÏÃæ²å×Å¼¸Ö»µãÈ¼µÄ»ğ°Ñ£¬µØÉÏÆÌ×ÅÏ¸Ï¸µÄÉ³×Ó£¬²ÈÉÏÈ¥¸ñÍâÊæ
ÊÊ¡£Ç°ÃæÒşÔ¼Í¸¹ıÀ´Ò»µãÁÁ¹â£¬´ó¸Å¾ÍÊÇ¶´¿ÚÁË¡£
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "Ê¯±Ú" : "[1;37m
                »¨      æÌ
                Óê      È»
                Æ®      Ò»
                Áã      Ğ¦
                Ğ¦      Ï·
                ºì      ¾Å
                ³¾      Ìì

[2;37;0m",
  "wall" : "[1;37m
                »¨      æÌ
                Óê      È»
                Æ®      Ò»
                Áã      Ğ¦
                Ğ¦      Ï·
                ºì      ¾Å
                ³¾      Ìì

[2;37;0m",
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong3",
  "north" : __DIR__"taoyuan1",
]));

	setup();
	replace_program(ROOM);
}
