// Room: /wiz/louth/a/xlu1.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ�����۵��ּ�С·��·���Ǹߴ�İ���������������
��Ũ�ܵ���Ҷ��͸����£�һ��΢�紵������Ҷɳɳ���졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"yu93",
  "southwest" : __DIR__"xlu2",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
