// Room: /wiz/louth/a/caodi2.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һƬ����Ĳݵأ�ϡ��ĳ��ż���С����ż����������
С������У�ʹ�˸��ܵ�һ�־��׵����ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"taoyuan10",
  "north" : __DIR__"caodi3",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
