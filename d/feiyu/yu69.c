// Room: /u/w/wangs/a/yu69.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�����ǰ��һ����ֱ��ɽ�壬����ǧ�ɣ��嶥��������
��Լ�ɼ���ɽ���ͺͺ�ģ����������㴦��ֻ��˳���±�ǰ
���߶���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu72",
  "north" : __DIR__"yu70",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
