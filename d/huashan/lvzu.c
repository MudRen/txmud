// Room: /d/huashan/lvzu.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������ǵ�ʿ�Ǽ������˵ĵط��������������ǰ�棬�ڷ�
��һ���㰸�������������ƣ���������������ε��������˵
�͵�����Ϣ̨��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"santai",
  "southeast" : __DIR__"xianguan",
]));
	
	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
