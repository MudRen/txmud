// Room: /d/fengtian/xh3.c

inherit ROOM;

void create()
{
	set("short", "�»�·");
	set("long", @LONG
�»�·�Ƿ��챱�ǱȽϷ�����һ���ֵ�������ۼ��˲��ٱ�
���ĵ��̣����к��ж�����ɫ�Ĳ�ݣ�·�߻���һЩС��������
�ɳ���ɽ�ϲɵĲ�ҩ����ʱ���������򵽲��ٺö�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lu1",
  "south" : __DIR__"xh2",
  "east" : __DIR__"hua",
  "north" : __DIR__"guanlu4",
]));

	set("objects",([
		NPC_DIR"xunpu" : 3,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
