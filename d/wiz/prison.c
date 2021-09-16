// Room: /d/wiz/prison.c
// ������������ by Find.

#define UNBLOCK_CMDS ({"say","reply","look","quit","from","read"})

inherit ROOM;

void create()
{
      set("short", "����");
        set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
        );
        set("no_clean_up", 0);

        setup();
}

void init()
{
        if(!wizardp(this_player()))
                this_player()->set("startroom",base_name(this_object()));
        add_action("block_cmds","",1);
}

int block_cmds()
{
        if(wizardp(this_player()))
                return 0;
        else if( member_array(query_verb(),UNBLOCK_CMDS) == -1 )
                return 1;
        else return 0;
}
