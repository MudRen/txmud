// miao.c
// by Find.
// modified by aiai

inherit ITEM;

protected int max_life = 1440, life = 0, dis = 4;
protected int water = 0, last_water_time, water_time;
protected int sun, sun_time;
protected int put, put_time;
protected int fei, success;
protected int water_limit=0;

int is_yao_miao() { return 1; }
void do_zai()
{
        put = 1;
        put_time = time();
        water = 0; water_time = 0; last_water_time = 0;
}

void create()
{
        set_name("发蔫的药苗", ({ "yao miao" }) );
        set_weight(500);


        set("unit", "株");
        set("long", "这是一株有些发蔫的药苗。\n");
        set("value",1);

        if(clonep())
                call_out("master_loop",dis);
}

protected void goto_die()
{
        object env;

        delete("value");

        if(objectp(env = environment()))
        {
                tell_object(env,sprintf("%s枯萎而死。\n",name()));
                if(env->is_room())
                        env->do_refresh();
        }

        destruct(this_object());
}

protected void master_loop()
{
        object env;

        if(!objectp(env = environment()))
        {
                destruct(this_object());
                return;
        }

        if(success)
                return;

        life += dis;

        if(life > max_life)
        {
                goto_die();
                return;
        }

        if(!env->is_room() || !env->query("outdoors"))
        {
                call_out("master_loop",dis);
                return;
        }

        // 白天被晒
        if( is_day() && (weather_now() == "clear") )
        {
                water = 0; water_time = 0; last_water_time = 0;
                sun_time += dis;

                if(sun_time >= 30)
                {
                        sun++;
                        sun_time = 0;
                        tell_object(env, sprintf("药苗被晒的%s枯萎了。\n",sun==1?"有些":"更加"));
                }

                if(sun >= 3)
                {
                        goto_die();
                        return;
                }
                else
                {
                        call_out("master_loop",dis);
                        return;
                }
        }

        if( is_day() || !put )
        {
                water = 0; water_time = 0; last_water_time = 0;
                call_out("master_loop",dis);
                return;
        }

        if(!water)
        {
                if(time() - put_time >= 30)
                {
                        call_out("goto_die",1);
                        return;
                }
                tell_object(env, "药苗有些发蔫，看来是要浇水了。\n");
                call_out("master_loop",dis);
                return;
        }

        if( (water > 4)
        || (water_time - last_water_time < 45) )        // 浇水间隔
        {
                tell_object(env, "因为浇水太多，药苗开始枯萎了。\n");
                call_out("goto_die",2);
                return;
        }

        if(water == 4)
        {
                if(time() - water_time > 40)
                {
                        tell_object(env, "因为肥料不足，药苗开始枯萎了。\n");
                        call_out("goto_die",2);
                        return;
                }
                tell_object(env, "药苗吸足了水份，枝叉都挺了起来，但叶子还有些\n枯黄，应该是施肥的时候了。\n");
                fei = 1;
                call_out("master_loop",dis);
                return;
        }

        if(time() - water_time >= 45)
        {
                if (++water_limit>2)
                {
                        water_limit=0;
                        tell_object(env, "因为长时间没有浇水，药苗开始枯萎了。\n");
                        call_out("goto_die",2);
                        return;
                }
                tell_object(env, "药苗有些发蔫，看来是要浇水了。\n");
        }

        call_out("master_loop",dis);
}

int time_to_fei() { return put&&fei&&!success?1:0; }

void do_fei()
{
        if(fei)
                call_out("do_success",2);
}

protected void do_success()
{
        tell_object(environment(), "药苗已经栽好，可以挖(wa)出来交差了。\n");
        set("name","药苗");
        set("long", "这是一株嫩绿的药苗。\n");
        success = 1;
}

void accept_pour()
{
        if(!is_day())
        {
                last_water_time = water_time;
                water_time = time();
                water++;
        }
}

int valid_get(object who)
{
        if(put)
                return notify_fail("药苗栽种在地里，你怎么\"捡\"？\n");
        else
                return 1;
}

int can_wa() { return put&&success?1:0; }

void do_wa() { put = 0; }

int is_success() { return success; }
