// kai191.c
// By dicky

inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这是一片荒废了的花园，本来这里有一片小池塘，养着一些金鱼
之类，现在池塘差不多也干涸了。池塘边立着一座假山，山上长满了
青苔，看来已经很久没有人来过了。
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
