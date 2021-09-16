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
        set_name("�����ҩ��", ({ "yao miao" }) );
        set_weight(500);


        set("unit", "��");
        set("long", "����һ����Щ�����ҩ�硣\n");
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
                tell_object(env,sprintf("%s��ή������\n",name()));
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

        // ���챻ɹ
        if( is_day() && (weather_now() == "clear") )
        {
                water = 0; water_time = 0; last_water_time = 0;
                sun_time += dis;

                if(sun_time >= 30)
                {
                        sun++;
                        sun_time = 0;
                        tell_object(env, sprintf("ҩ�类ɹ��%s��ή�ˡ�\n",sun==1?"��Щ":"����"));
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
                tell_object(env, "ҩ����Щ���裬������Ҫ��ˮ�ˡ�\n");
                call_out("master_loop",dis);
                return;
        }

        if( (water > 4)
        || (water_time - last_water_time < 45) )        // ��ˮ���
        {
                tell_object(env, "��Ϊ��ˮ̫�࣬ҩ�翪ʼ��ή�ˡ�\n");
                call_out("goto_die",2);
                return;
        }

        if(water == 4)
        {
                if(time() - water_time > 40)
                {
                        tell_object(env, "��Ϊ���ϲ��㣬ҩ�翪ʼ��ή�ˡ�\n");
                        call_out("goto_die",2);
                        return;
                }
                tell_object(env, "ҩ��������ˮ�ݣ�֦�涼ͦ����������Ҷ�ӻ���Щ\n�ݻƣ�Ӧ����ʩ�ʵ�ʱ���ˡ�\n");
                fei = 1;
                call_out("master_loop",dis);
                return;
        }

        if(time() - water_time >= 45)
        {
                if (++water_limit>2)
                {
                        water_limit=0;
                        tell_object(env, "��Ϊ��ʱ��û�н�ˮ��ҩ�翪ʼ��ή�ˡ�\n");
                        call_out("goto_die",2);
                        return;
                }
                tell_object(env, "ҩ����Щ���裬������Ҫ��ˮ�ˡ�\n");
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
        tell_object(environment(), "ҩ���Ѿ��Ժã�������(wa)���������ˡ�\n");
        set("name","ҩ��");
        set("long", "����һ�����̵�ҩ�硣\n");
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
                return notify_fail("ҩ�������ڵ������ô\"��\"��\n");
        else
                return 1;
}

int can_wa() { return put&&success?1:0; }

void do_wa() { put = 0; }

int is_success() { return success; }
