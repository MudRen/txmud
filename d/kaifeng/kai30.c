// Room: /u/w/wangs/b/kai30.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ͨ�˼ң��������ں���·����һ��С���̣�����
���ӹ��õ�����ʵ��������ͯ����Ժ�����˵�Ϊ�֣�һ�����¸�
�����ڴ�ǰ�������΢Ц��������ɣ�������������ͯ��̬֮��
�뻭��֮�С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai29",
]));
        set("objects",([
        __DIR__"npc/zfuren": 1,
        __DIR__"npc/zhangnn": 1,
]));

	setup();
	replace_program(ROOM);
}
