// Room: /d/huashan/ligou.c

inherit ROOM;

void create()
{
	set("short", "�Ͼ��繵");
	set("long", @LONG
���Ǽж���ʯ�ڼ��һ����״��·����570�༶ʯ�ף�����
·�����ʵǼ��ѡ���˵����̫���Ͼ��ڴ�����ʱ�������ǿ�ɽ��
·̫���ˣ���ǣ����ţ��һҹ֮���������ɽ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qunxian",
  "northeast" : __DIR__"husunchou",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
