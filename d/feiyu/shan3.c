// Room: /wiz/louth/a/shan3.c

inherit ROOM;

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·�������Ƕ��͵����£������ϻ�����һ
ЩС���ݣ�ɽ�紵����ҡҡ�λΡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shan4",
  "westdown" : __DIR__"shan2",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}