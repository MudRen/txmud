// Room: /d/path5/ccg07.c

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
������Ƕ���ɽ�ˣ��ɴ�������ȥ����ɽ��������ظ�ԭ�ˣ�
�򶫲�Զ���ǵ��ɶ���������һ��С·��֪ͨ��η�����������
����ʯ�����ˣ���ʱ�޷�ͨ����·��������һ�����ӡ�
LONG
	);
	set("item_desc",([
          "����":"
                  eastdown     �ɶ�
                  west         ��֥ \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg08",
  "eastdown" : __DIR__"ccg06",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
