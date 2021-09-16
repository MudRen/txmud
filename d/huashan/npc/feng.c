// huashan master-feng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_DTIME;

string ask_me(object who);

string tell_secret_dang();
string tell_secret_yujian();

int do_bihua(object me);
void do_perform_player(int flag);

string cancel_player_pfm();


void create()
{
        set_name("������", ({ "master feng"}) );
        set("nickname",WHT"���½�ʥ"NOR);
        set("gender", "����" );
        set("class", "huashan");

        set("age", 84);
        set("str", 80);
        set("cor", 30);
        set("int", 60);
        set("per", 30);
        set("con", 60);
        set("kar", 60);

        set("max_force", 20000);
        set("force", 20000);
        set("force_factor", 60);

        set_disappear_msg("\n��ֻ������ǰһ��������һ�����������Ѿ������ˡ�\n");
        set_appear_time(([
        ",,1380":",,300",
]));

        set("max_gin",10000);
        set("max_kee",10000);
        set("max_sen",10000);

        set("long",@LONG
������������Ⱥ��ʦ�壬һ�������ڽ�������
�ڹ�����»ȴ�����⡣��������Ⱥ��ʦ�����ͣ�
�������ĺ��Խ����ѣ���������Ը��
LONG );

        create_family("��ɽ��", 2, "ʦ��");

        set("combat_exp", 7000000);

        set("dugu_pfm_yujian", 1);
        set("dugu_pfm_dang", 1);

        set_skill("unarmed", 250);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("literate", 300);
        set_skill("sword", 300);
        set_skill("dugu-sword",300);
        set_skill("force", 300);
        set_skill("lingyun-steps",300);
        set_skill("fuyunshou", 250);
        set_skill("zixia-force",250);

        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "dugu-sword");
        map_skill("dodge", "lingyun-steps");

        set("inquiry", ([
                "yujian" : (: tell_secret_yujian :),
                "dang" : (: tell_secret_dang :),
                "����ʽ" : (: tell_secret_yujian :),
                "����ʽ" : (: tell_secret_dang :),
                // ������-- cancel
                "cancel" : (: cancel_player_pfm :),
]) );

        setup();
                carry_object(ARMOR_DIR"cloth")->wear();
                carry_object(WEAPON_DIR"bamboo_sword")->wield();
}

void init()
{
        add_action("do_bihua", "bihua");
}

void attempt_apprentice(object ob)
{
        if(ob->query("class") != "huashan")
                return;

        if(ob->query_skill("huashan-sword",1))
        {
                command("say ��Ȼ�����л�ɽ���������ڵ��ӣ�ȥ������Ⱥ���š������������ɡ�");
                command("heng");
                return;
        }

        if(ob->query("int") < 31)
        {
                command("say ���½���������ʤ���У��ء��򡱲��ء�ѧ����������Բ��̫Զ�ˡ�");
                command("shake");
                return;
        }

        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
                "���Ŭ�������ձض��гɡ�\n");

        command("recruit " + ob->query("id") );
        ob->save();
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}


int prevent_learn(object who,string skill)
{
        int n;

        if(who->query_skill("huashan-sword",1))
                return notify_fail("��Ȼ�����л�ɽ���������ڵ��ӣ�ȥ������Ⱥ���š������������ɡ�\n");

        n = query_time();
        if((n < 1380) && (n > 300))
                return notify_fail("������Ҫ��ȥ���ߣ������������ɡ�\n");
        return 1;
}


string tell_secret_dang()
{
        object me, ob;

        me=this_player();
        ob=this_object();

        if ( me->query("dugu_pfm_dang") )
        {
                return RANK_D->query_respect(me)+"�Ѿ�ѧ�᡺����ʽ���Ŀھ��ˡ�\n";
        }

        if ( me->query_temp("asked_about_dang") )
        {
                return "���Ǹ��߹�������"
                        +RANK_D->query_respect(me)+"�ļ��Ա��Ϸ򻹲��\n";
        }

    if ( me->query("class") != "huashan" )
        {
                command("shake");
                return "�㲻�ǻ�ɽ�ɵ��ˣ��������ʲô��\n";
        }

        if ( me->query_skill("huashan-sword") )
        {
                return "���ڵĵ����޷���᡺����ʽ�����㻹�ǻ�ȥ�ɡ�\n";
        }

        if ( !me->query_skill("dugu-sword") )
        {
                return "��û�����ն��¾Ž�����̸������ʽ����\n";
        }

        if ( (int)me->query_skill("dugu-sword",1)<260 ||
                 (int)me->query("combat_exp",1)<3000000 )
        {
                return "��Ĺ��򲻵��ң����ں���˵������ʽ��Ϊʱ���硣\n";
        }
        
        command("nod");
        me->set_temp("asked_about_dang", 1);
return RANK_D->query_respect(me)+
"��һ�����������ڼ���ϰ���Ϸ�ܸ����һ�ɽ�����ں��
���ˡ��Ϸ��Ѷ��겻�á�����ʽ������˲�������ָ��"+
RANK_D->query_respect(me)+"���еľ��裬��
���Ϸ�����ʱ����������ʽ���ھ�д����һ���־����棬�����ڻ�ɽ�ɵ�ɽ��
֮�£������ȥ���ҿ������������Ϸ��´˿ھ����ڶ���֮�֣������˻�����
�����ؼ���ǧ��С�ģ�\n";

}


string tell_secret_yujian()
{
        object me, ob;
        string msg;

        me=this_player();
        ob=this_object();

    if ( (int)me->query("dugu_pfm_yujian", 1)==1 )
        return RANK_D->query_respect(me)+"�Ѿ�ѧ�᡺����ʽ�����Ժ�Ҫ�������壬������ɱ�޹���\n";

    if ( me->query_temp("asked_about_yujian") )
         return "���Ǻ���˵����"+
              RANK_D->query_respect(me)+"�ļ��Ա��Ϸ򻹲��\n������Ǻǵ�Ц�˼�����\n";

    if ( me->query("class") != "huashan" )
        {
            command("shake");
            return "�㲻�ǻ�ɽ�ɵ��ˣ��������ʲô��\n";
        }

    if ( me->query_skill("huashan-sword") )
            return "�������ڵĵ��ӣ��޷���᡺����ʽ�������ǻ�ȥ�ɡ�\n";

    if ( !me->query_skill("dugu-sword") )
            return "��û�����ն��¾Ž����ǲ���ϰ�á�����ʽ���ġ�\n";

    if ( (int)me->query_skill("dugu-sword",1)<200 ||
             (int)me->query("combat_exp",1)<2500000 )
            return "��Ĺ��򲻵��ң����ڽ��㡺����ʽ��Ϊʱ���硣\n";
        
    command("nod");

    msg=RANK_D->query_respect(me)+
"����ѧϰ������ʽ�������Ϸ��ָ��ָ�㡣�����Ϸ�ġ�����ʽ��
����ʵս�вſ���ᣬ����׼���ã����Ժ��Ϸ�Ȼ� (bihua) һ�£����ܰ���ס
�Ϸ�ġ�����ʽ�����ͽ��ھ��������㡣\n";

    me->set_temp("asked_about_yujian", 1);
    me->set_temp("asked_yujian_fight", 1);
    return msg;
        
}

int do_bihua(string str)
{
        object weapon, who;

        if (!str) return notify_fail("��Ҫ��˭�Ȼ���\n");
        if (str!="master feng" && 
                str!="feng" && 
                str!="mf") 
                return notify_fail("��Ҫ��˭�Ȼ���\n");

        who=this_player();
                
    if ( !who->query_temp("asked_yujian_fight") )
        {
            write("������˵�����Ϸ����˳��������꣬�����"+RANK_D->query_respect(who)+"ƴɱ��\n");
            return 0;
        }

        write("������˵������Ȼ"+RANK_D->query_respect(who)+
                "ͬ�⣬�Ϸ��ͬ������С�\n");

    if (!this_object()->query_temp("weapon"))
        {
            weapon=present( "sword", environment(this_object()) );
            if (weapon)
                    this_object()->wield(weapon->query("id"));
            else
                    carry_object(WEAPON_DIR"bamboo_sword")->wield();
            write("������������һ�����������С�\n");
        }

    this_object()->fight_ob(who);
    who->fight_ob(this_object());
    call_out("do_perform_player", 5, -1);
    return 1;
}

void do_perform_player(int flag)
{
        object ob, me;

        me=this_player();
        ob=this_object();

    if (environment(me)!=environment(ob))
        {
            tell_object(me, "\n��ȡ���˺ͷ�����ı��ԡ�\n");
            return;
        }

    if (ob->query_temp("unconcious"))
        {
            tell_object(me, "\n���������ﲻ�ܼ�����������ˡ�\n");
            return;
        }

    if ( (!me->is_fighting() ||
             !ob->is_fighting()) &&
             flag<3 )
        {
            ob->remove_all_enemy();
            me->remove_all_enemy();
            tell_object(me, "\n�������ս�˵��������"+RANK_D->query_respect(this_player())+
          "����û��׼���ã����ǵ�׼������֮����˵�ɡ�\n");
            remove_call_out("do_perform_player");
            return;
        }

    if ( !ob->query_temp("weapon") )
        {
            ob->remove_all_enemy();
            me->remove_all_enemy();
            tell_object(me, "\n������������˵����"+
          RANK_D->query_respect(this_player())+
          "��Ȼ��ѧϰ������ʽ������Ҫ����ս������ҪϷŪ�Ϸ�\n");
            remove_call_out("do_perform_player");
            me->delete_temp("asked_yujian_fight");
            return;
        }

    if (flag == -1)
        {
            tell_object(me, HIY"\n������˵����"+
          RANK_D->query_respect(this_player())+
          "С�ģ��Ϸ�Ҫ��������ʽ���ˣ�\n\n"NOR);
            call_out("do_perform_player", 3, 1);
            return;
        }

    if (flag == 1)
        {
            ob->perform_action("sword.yujian "+me->query("id"));
            call_out("do_perform_player", 5, 2);
            return;
        }

    if (flag == 2)
        {
            ob->remove_all_enemy();
            me->remove_all_enemy();
            tell_object(me, "\n���������һ�ݣ������ջء�\n");
            call_out("do_perform_player", 2, 3);
            return;
        }

    if (flag == 3)

        {
            tell_object(me, WHT"\n
�������ս�˵�����ã���Ȼ���������˲ų����Ϸ�ͽ�������ʽ���Ŀھ��������㣬
ϣ�����Ժ����߽���Ҫ�������壬�мǲ�����ɱ�޹�������ɽ�������¶ˡ�\n"NOR);
            call_out("do_perform_player", 3, 4);
            return;
        }

    if (flag == 4)
        {
            tell_object(me, WHT"\n�����ｫ���¾Ž�������ʽ���Ŀھ����ڸ��㡣\n\n"NOR);
            call_out("do_perform_player", 4, 5);
            return;
        }

    if (flag == 5)
        {
            tell_object(me, HIC"�����������ˡ�����ʽ����\n\n"NOR);
            me->set("dugu_pfm_yujian", 1);
            me->delete_temp("asked_yujian_fight");
            me->delete_temp("asked_about_yujian");
            return;
        }
}

string cancel_player_pfm()
{
    object me = this_player();
    if (!wizardp(me))
            return 0;
    me->delete("dugu_pfm_dang");
    me->delete("dugu_pfm_yujian");
    return "��ġ�����ʽ���͡�����ʽ���Ѿ��������ˣ�����������\n";
}
