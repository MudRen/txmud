// Room: /d/huashan/qianchi.c

inherit ROOM;

void create()
{
	set("short", "ǧ���");
	set("long", @LONG
���ﹲ��370�༶ʯ�ף�ɽ���쳣��խ��ֻ����һ��ͨ����
�����±ڶ��ͣ�ͷ��ֻ��һ����⣬����Σ�ա�����ʯ�ף���ֻ
�ܴ�һ����С��ʯ���������ʯ�����С��쾮�������Ϸ���һ��
���壬ֻҪ������Ѷ��ڸ��ϣ����¾���·�����ˡ�
LONG
	);

	set("NONPC", 1);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huixin",
  "eastup" : __DIR__"baichi",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
