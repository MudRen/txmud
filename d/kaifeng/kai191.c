// kai191.c
// By dicky

inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ�ķ��˵Ļ�԰������������һƬС����������һЩ����
֮�࣬���ڳ������Ҳ�ɺ��ˡ�����������һ����ɽ��ɽ�ϳ�����
��̦�������Ѿ��ܾ�û���������ˡ�
LONG);
        set("outdoors", "kaifeng");
        set("exits", ([
                "west" : __DIR__"kai190",
        ]));

	set("objects", ([
		"/d/gaibang/npc/xiao" : 1,
	]));

        setup();
        replace_program(ROOM);
}
