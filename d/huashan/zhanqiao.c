// Room: /d/huashan/zhanqiao.c

inherit ROOM;

void create()
{
	set("short", "����ջ��");
	set("long", @LONG
����һ��������ɽ֮���ջ�ţ����¸����ι�������������
�����ɾ�����ɽ���Դӷ���������󳡣�Ϊ�˲ɿ����������ջ
�š������м�����ɽ�ɵ��������ţ���������ǻ�ɽ�ɵ��ˣ���
����۹�һ�¾����ˣ�������ȥ�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
 
  "west" : __DIR__"shanlu2",
  "east":__DIR__"luoyun",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
