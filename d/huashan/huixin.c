// Room: /d/huashan/huixin.c

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�����ͱڴ�����ǰ��������л���ʯ�������֣��������һ
�����ڡ����ϡ��Ĺ��¡�����ǧ�ߴ������������ͱ�֮�ϣ���խ
��ʯ���������ϡ���Դ��վ�����������η�������ʵǣ�����ת
�⣬ѭԭ·���£����ǻ���ʯ����һ�ֺ��塣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"e_daoguan",
  "east" : __DIR__"qianchi",
  "northwest" : __DIR__"xianguan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
