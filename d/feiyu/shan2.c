// Room: /wiz/louth/a/shan2.c

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
  "eastdown" : __DIR__"shan1",
  "eastup" : __DIR__"shan3",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
