// hl_grass.c
// by Find.
// modified by aiai

inherit ITEM;

protected int dis = 3,dry, max_dry = 25;
protected string master;
protected int lost = 60*2;    // 2分钟任务id不在，呼啦草就会消失

int keep_in_room() { return 1; }

string q_long()
{
        return sprintf("这是一把大同东南山区的特产呼啦草，\n以编(bian)出的草鞋松软舒适而著称。\n%s%s",
                dry>=max_dry?"看样子已经非常干燥了\n":"",
                master?master+"\n":"");
}

void set_master(string m)
{
        if(!stringp(m) || (m == "") || master)
                return;

        else
                master = m;
}

string query_master() { return master; }

void create()
{
        set_name("呼啦草", ({ "hu la cao" }) );
        set_weight(500);

        set("unit", "把");
        set("long", (: q_long :));
        set("value",1);

        if( clonep() )
                call_out("dest_me", lost);

}

void init()
{
        if(find_call_out("check_env") == -1)
                call_out("check_env",dis);

        add_action("do_bian","bian");
}

int do_bian()
{
        object *cao, me = this_player();
        string id;

        if(environment() != me)
                return 0;

        id = me->query("id");

        if(!master)
                master = id;

        if(master != id)
                return 0;

        if(dry < max_dry)
                return notify_fail("呼啦草还没有干透，没法编制草鞋。\n");

        cao = filter_array(all_inventory(me),
                (: ($1 != this_object())
                && ($1->query("id") == "hu la cao")
                && $1->is_dry()
                && ($1->query_master() == master) :));

        if(!sizeof(cao))
        {
                write("编制一双草鞋需要两把呼啦草。\n");
                return 1;
        }

        me->start_busy(10);
        message_vision("$N抓起两把呼啦草，开始认真的编起草鞋来。\n",me);

        if (random(me->query_kar())<12)
           call_out("fail_bian", 4, me, cao[random(sizeof(cao))]);
        else call_out("finish_bian", 6, me, cao[random(sizeof(cao))]);
        return 1;
}

protected void fail_bian(object me, object other)
{
        if( !me || (environment() != me) || (environment(other) != me) )
        {
                me->stop_busy();
                return;
        }

        message_vision("$N一个不小心，穿错了线，草鞋编坏了。\n", me);

        destruct(other);
        me->stop_busy();
        destruct(this_object());
}

protected void finish_bian(object me, object other)
{
        object xie;

        if( !me || (environment() != me) || (environment(other) != me) )
        {
                me->stop_busy();
                return;
        }

        message_vision(sprintf("$N编好一双草鞋，看了看，%s笑了起来。\n",
                me->query("gender") == "男性"?"裂开嘴":"高兴的"), me);

        destruct(other);
        xie = new(__DIR__"xie");
        xie->move(me);
        xie->set_master(master);
        me->stop_busy();
        destruct(this_object());
}

protected void dest_me()
{
        if(dry >= max_dry)
                return;

        if(environment())
            if(environment()->is_room())
                tell_object(environment(),"呼啦草没人看着，被风刮跑了。\n");
            else tell_object(environment(),"呼啦草慢慢的烂掉了。\n");
        destruct(this_object());
}

protected void check_env()
{
        object env,room;
        string weather, move;
        mapping exits;

        if( !objectp(env = environment())
        || !env->is_room()
        || (!env->query("outdoors") && !env->is_hy_drying_room()) )
                return;

        if(!present(master, env) &&
                !this_object()->query_temp("bian"))
        {
                this_object()->delete_temp("just_here");
                if(find_call_out("dest_me") <= 0)
                        call_out("dest_me", lost);
                call_out("check_env",dis);
                return;
        }
        else if (!this_object()->query_temp("just_here"))
        {
                this_object()->set_temp("just_here", 1);
                if(find_call_out("dest_me") > 0)
                        remove_call_out("dest_me");
        }

        if(dry >= max_dry)
                return;

        if(env->is_hy_drying_room())
        {
                if(++dry >= 15)
                {
                        dry = max_dry;
                        if(find_call_out("dest_me") > 0)
                                remove_call_out("dest_me");
                        tell_object(env,"呼啦草已经完全晾干了。\n");
                        return;
                }
                call_out("check_env",dis);
                return;
        }

        if( ((weather = weather_now()) != "clear") && (weather != "wind") )
        {
                dry = 0;
                call_out("check_env",dis);
                return;
        }

        if(!is_day())
        {
                call_out("check_env",dis);
                return;
        }

        if(weather == "clear")
        {
                if(++dry >= max_dry)
                {
                        if(find_call_out("dest_me") > 0)
                                remove_call_out("dest_me");
                        tell_object(env,"呼啦草已经完全晾干了。\n");
                        return;
                }
        }

        else if( (weather_degree() != "begin")
        && !random(4)
        && mapp(exits = query("exits"))
        && sizeof(exits) )
        {
                move = values(exits)[random(sizeof(exits))];
                if(!(room = find_object(move)))
                        room = load_object(move);
                if(room)
                {
                        tell_object(env,"一阵风吹过，把呼啦草吹跑了。\n");
                        if(move(room))
                                tell_object(environment(),"一阵风把一把呼啦草吹了过来。\n");
                }

                if(++dry >= max_dry)
                {
                        if(find_call_out("dest_me") > 0)
                                remove_call_out("dest_me");
                        tell_object(environment(),"呼啦草已经完全晾干了。\n");
                        return;
                }
        }

        call_out("check_env",dis);
        return;
}

int is_dry() { return dry >= max_dry; }
