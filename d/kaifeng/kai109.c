// Room: /u/w/wangs/b/kai109.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǿ���ǵĹ����ˡ������ϵ������������ģ��쳣æ
µ�������﹤���Ĵ���ǿ�������ƶ���˼ҡ�Ҳ��һЩ�����
�����ˡ������Ƕ���һ����֮ͬ��������ƾ���ǵĺ�ˮ��������
���ͼ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"kai110",
  "west" : __DIR__"kai108",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
