// Room: /wiz/louth/a/xlu2.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ�����۵��ּ�С·��·���Ǹߴ�İ���������������
��Ũ�ܵ���Ҷ��͸����£�һ��΢�紵������Ҷɳɳ���졣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xlu1",
  "south" : __DIR__"zting",
  "southwest" : __DIR__"xlu3",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
