// Room: /d/huashan/tieku.c

inherit ROOM;

private void check_weight(object who);

void create()
{
        set("short", "铁石场");
        set("long", @LONG
这里便是华山铸剑池炼铁场的铁矿场了，只见铁矿石堆积的
像小山一般，一位中年弟子正在把运来的铁矿石过秤。
LONG
);

        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhujian",
  "north" : __DIR__"sroad1",
]));

        set(SAFE_ENV,1);

        set("objects",([
        __DIR__"npc/shi_daizi" : 1,
]));
        setup();
}

void init()
{
        object me = this_player();

        if( me && (me->query("class") == "huashan") )
                call_out( (: check_weight :),2,me );
}

private void check_weight(object me)
{
        object *inv;
        int i,n,weight = 0;
        string name;

        if(!me || (environment(me) != this_object()))
                return;

        name = me->query("id");

        if(!n=sizeof(inv = filter_array( deep_inventory(me),
                (: $1->is_huashan_tiekuang() && ($1->query_master() == $(name)) :))))
        {
                write("\n施戴子对你说道：抓紧时间好好练功，没事别四处瞎转游。\n\n");
                return;
        }

        for(i=0; i<n; i++)
        {
                weight += inv[i]->weight();
                        destruct(inv[i]);
        }

        if(!weight)
        {
                write("\n施戴子对你说道：抓紧时间好好练功，没事别四处瞎转游。\n\n");
                return;
        }

        message_vision("\n$N把运来的铁矿石扔到了矿石堆里，人也累坏了。\n",me);

        if(me->query("combat_exp") > 50000)
        {
                write("\n施戴子对你说道：师傅交待过，这些活是让刚入门的弟子做得，借以磨练体质，
    像你这样的根基还是多练功吧，华山武学要在我辈手中发扬光大！！\n\n");
                return;
        }

        weight /= 2500;
        me->add("combat_exp",weight);
        me->add("potential",weight/2);

        tell_object(me,sprintf("\n你得到了：\n %3d 点经验\n %3d 点潜能\n你的纵跃闪躲之术有所进步\n\n",
                weight,weight/2));
        me->improve_skill("dodge",weight/2);
}

