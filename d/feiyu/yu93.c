// Room: /wiz/louth/a/yu93.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����������ĺ��ţ�������һƬ���֣������дУ�
һ��С·ֱͨ������֮�С�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yu94",
  "north" : __DIR__"yu92",
  "southwest" : __DIR__"xlu1",
]));

       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
