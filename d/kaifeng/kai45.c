// Room: /u/w/wangs/b/kai45.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ÿ����ƣ�ֻҪ���������ﲻʱ��������˻��������̤��
����Ϳ���֪��������ʲô�ط��ˡ�����İ���Ҳ���Ҳ�ͬ��
�����������ڿ��ŵ�һ��б����һ��С��̨��ֱ�Դ��ŵ�ǽ��
����һ�ź���İ˿�ͼ������֮��һ�����У�������ͨ����Ժ��
�ŵ��Ǻܿ��������������ƥ��ͬʱ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai43",
  "east" : __DIR__"kai46",
]));
        set("objects",([
        __DIR__"npc/huoji":1,
]));

	setup();
	replace_program(ROOM);
}
