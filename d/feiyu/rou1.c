// Room: /wiz/louth/a/rou1.c

inherit ROOM;

void create()
{
	set("short", "[35mÈáÇé¹È[2;37;0m");
	set("long", @LONG
´äÖñÇàÇà£¬·É»¨Á÷Ë®£¬Ô¶¼ûÆÙ²¼ĞüÌì£¬½üÎÅÄñÃùÉùÉù¡£
ï£ï£Ë¿ÖñÈçÌìÒôäıäı£¬Ğ¡ÇÅÁ÷Ë®¸üÔö¹ÅÒâ°»È»¡£
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"rou5",
  "north" : __DIR__"rou2",
]));

        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/ziyi" : 1,
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
