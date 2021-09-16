// /d/path3/k_h35.c

inherit ROOM;

void create()
{
        set("short", "竹笠坡");
        set("long", @LONG
这里就是竹笠坡。听说当初苏东坡在此，看到女人手工制造
的精美竹笠而给此命名。不过现在做这个的好像不多了。西边是
一片竹林，林边树着一个牌子。
LONG
);
        set("item_desc", ([
                "牌子" : "
                  northwest    长江渡口
                  south        杭州城 
",
        ]));

        set("exits", ([
                "south" : "/d/path3/k_h36",
                "northwest" : "/d/path3/k_h34",
                "west" : __DIR__"hz_maze/entry",
                "east" : __DIR__"hz_maze/exit",
        ]));

        set("outdoors", "hangzhou");

        setup();
}

