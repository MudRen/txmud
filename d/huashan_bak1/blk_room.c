// Room: /d/huashan/blk_room.c

inherit ROOM;

void create ()
{
        set("short", "����");
    set("long", @LONG
������һ��ǳ��谵��С�ݣ�����͸����С���촰����ֻ��
ģ�������������ܡ�С����ɭ���䣬���������ǹ�Ѻ�����˵���
����Ҳ��Ҫ��ϸ����һ�¡�
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"blk_road2",
]) );

  set("light_up", 1);

  setup();
}

void init()
{
   add_action("do_diaocha","diaocha");
   add_action("do_diaocha","check");
   add_action("open_my_door","za");
   add_action("enter_my_door","enter");
}

int do_diaocha(string str)
{
        tell_object(this_player(),"����ϸ������һ�£�������һ��ǽ��Щ��֣�Ҳ���Ǹ����š�\n");
        return 1;
}

int open_my_door(string str)
{

    if (!str)
                return notify_fail("��Ҫ��ʲô��\n");
        if (str!="ǽ" && str!="wall")
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query("force",1)<1000 ||
                this_player()->query_str()<40)
                return notify_fail("�������Ҷ����ǽ������ǽȴ��˿������\n");

        tell_object(this_player(),"���������������ȡ���һ��������ǽ�İ����ƿ��ˡ�\n");
    this_player()->start_busy(2);
        this_player()->set_temp("dilao_enter", 1);
        this_player()->add("force", -600);
        return 1;
}

int enter_my_door(string str)
{
    if (!str || !this_player()->query_temp("dilao_enter"))
                return notify_fail("��������\n");
        if (str!="dilao" && str!="prizon" && str!="����")
                return notify_fail("��������\n");
        message_vision("$N�߽��˰��š�\n���š�ž����һ�������ˣ�\n",this_player());
        this_player()->delete_temp("dilao_enter");
        this_player()->move(__DIR__"dilao");
        return 1;
}


