// Room: /wiz/louth/a/xlu3.c

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
  "northeast" : __DIR__"xlu2",
  "southwest" : __DIR__"xlu4",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
