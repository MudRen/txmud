// Room: /d/huashan/baichi.c

inherit ROOM;

void create()
{
	set("short", "�ٳ�Ͽ");
	set("long", @LONG
�ٳ�Ͽ��Ͽ�����ߡ���������ɽ֮��ֻ������Σ��������
����µ�ʯ�������������ɽ��ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qunxian",
  "westdown" : __DIR__"qianchi",
]));
        set("outdoors", "huashan"); 
	setup();
	replace_program(ROOM);
}
