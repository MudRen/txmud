// Room: /u/w/wangs/b/kai107.c

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
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kai108",
  "west" : __DIR__"kai105",
]));
        set("objects",([
        __DIR__"npc/gongren":1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
