// Room: /d/huashan/dongfeng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǻ�ɽ�Ķ��壬Ҳ��Ҳ���������壬�ǻ�ɽ���ճ���
���ɽ�塣�ڶ����ϣ���һ���������Ƶ�ʯ�ڣ���˵�Ǿ�������
�µ���ӡ�����ܵ��Ͽ�����Ұ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"shanquan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
