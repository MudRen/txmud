// Room: /u/w/wangs/b/kai150.c

inherit ROOM;

void create()
{
	set("short", "�ھִ���");
	set("long", @LONG
�����еĳ��裬ȫ��ʮ�־��µ���̴ľ�Ҿߣ��������Ⱦ޴�
�İ�ߡ���磬���������˸�ɫ�������ɼ��������İ���ͼ����
�Ǻ����Ĺ�����Ҹ�������̫ʦ�Σ���Ϊ����׼���ġ�������
�������߸���һ��ƫ����ƫ����ס����һЩ��ʦ�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai149",
  "north" : __DIR__"kai155",
  "west" : __DIR__"kai154",
  "east" : __DIR__"kai153",
]));
        set("objects",([
        __DIR__"npc/wubt": 1,
]));

	setup();
	replace_program(ROOM);
}
