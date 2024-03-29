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
        set_name("风清杨", ({ "master feng"}) );
        set("nickname",WHT"独孤剑圣"NOR);
        set("gender", "男性" );
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

        set_disappear_msg("\n你只觉得眼前一闪，定睛一看，风清杨已经不见了。\n");
        set_appear_time(([
        ",,1380":",,300",
]));

        set("max_gin",10000);
        set("max_kee",10000);
        set("max_sen",10000);

        set("long",@LONG
风清杨是岳不群的师叔，一生醉心于剑术。对
于功名利禄却不在意。因与岳不群的师父不和，
便云游四海以剑会友，倒遂了素愿。
LONG );

        create_family("华山派", 2, "师叔");

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
                "御剑式" : (: tell_secret_yujian :),
                "荡剑式" : (: tell_secret_dang :),
                // 测试用-- cancel
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
                command("say 既然是深研华山剑法的气宗弟子，去找岳不群等着“以气御剑”吧。");
                command("heng");
                return;
        }

        if(ob->query("int") < 31)
        {
                command("say 独孤剑法以无招胜有招，重“悟”不重“学”，你的悟性差的太远了。");
                command("shake");
                return;
        }

        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + 
                "多加努力，他日必定有成。\n");

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
                return notify_fail("既然是深研华山剑法的气宗弟子，去找岳不群等着“以气御剑”吧。\n");

        n = query_time();
        if((n < 1380) && (n > 300))
                return notify_fail("白天我要出去走走，你晚上再来吧。\n");
        return 1;
}


string tell_secret_dang()
{
        object me, ob;

        me=this_player();
        ob=this_object();

        if ( me->query("dugu_pfm_dang") )
        {
                return RANK_D->query_respect(me)+"已经学会『荡剑式』的口诀了。\n";
        }

        if ( me->query_temp("asked_about_dang") )
        {
                return "不是告诉过你了吗，"
                        +RANK_D->query_respect(me)+"的记性比老夫还差啊。\n";
        }

    if ( me->query("class") != "huashan" )
        {
                command("shake");
                return "你不是华山派的人，问这个做什么？\n";
        }

        if ( me->query_skill("huashan-sword") )
        {
                return "气宗的弟子无法领会『荡剑式』，你还是回去吧。\n";
        }

        if ( !me->query_skill("dugu-sword") )
        {
                return "你没有掌握独孤九剑，何谈『荡剑式』？\n";
        }

        if ( (int)me->query_skill("dugu-sword",1)<260 ||
                 (int)me->query("combat_exp",1)<3000000 )
        {
                return "你的功夫不到家，现在和你说『荡剑式』为时过早。\n";
        }
        
        command("nod");
        me->set_temp("asked_about_dang", 1);
return RANK_D->query_respect(me)+
"有一定的资质又勤加练习，老夫很高兴我华山派气宗后继
有人。老夫已多年不用『荡剑式』，因此不能亲自指点"+
RANK_D->query_respect(me)+"其中的精髓，不
过老夫年轻时曾将『荡剑式』口诀写在了一本手卷上面，并藏于华山派的山崖
之下，你可以去找找看，不过当年老夫怕此口诀落于恶人之手，安置了机关人
看守秘籍，千万小心！\n";

}


string tell_secret_yujian()
{
        object me, ob;
        string msg;

        me=this_player();
        ob=this_object();

    if ( (int)me->query("dugu_pfm_yujian", 1)==1 )
        return RANK_D->query_respect(me)+"已经学会『御剑式』，以后要行侠仗义，不能乱杀无辜。\n";

    if ( me->query_temp("asked_about_yujian") )
         return "不是和你说了吗，"+
              RANK_D->query_respect(me)+"的记性比老夫还差啊。\n风青扬呵呵的笑了几声。\n";

    if ( me->query("class") != "huashan" )
        {
            command("shake");
            return "你不是华山派的人，问这个做什么？\n";
        }

    if ( me->query_skill("huashan-sword") )
            return "你是气宗的弟子，无法领会『御剑式』，还是回去吧。\n";

    if ( !me->query_skill("dugu-sword") )
            return "你没有掌握独孤九剑，是不能习得『御剑式』的。\n";

    if ( (int)me->query_skill("dugu-sword",1)<200 ||
             (int)me->query("combat_exp",1)<2500000 )
            return "你的功夫不到家，现在教你『御剑式』为时尚早。\n";
        
    command("nod");

    msg=RANK_D->query_respect(me)+
"有心学习『御剑式』，那老夫就指点指点。不过老夫的『御剑式』
需在实战中才可领会，你若准备好，可以和老夫比划 (bihua) 一下，若能挨得住
老夫的『御剑式』，就将口诀传授于你。\n";

    me->set_temp("asked_about_yujian", 1);
    me->set_temp("asked_yujian_fight", 1);
    return msg;
        
}

int do_bihua(string str)
{
        object weapon, who;

        if (!str) return notify_fail("你要和谁比划？\n");
        if (str!="master feng" && 
                str!="feng" && 
                str!="mf") 
                return notify_fail("你要和谁比划？\n");

        who=this_player();
                
    if ( !who->query_temp("asked_yujian_fight") )
        {
            write("风青扬说道：老夫已退出江湖多年，不想和"+RANK_D->query_respect(who)+"拼杀。\n");
            return 0;
        }

        write("风青扬说道：既然"+RANK_D->query_respect(who)+
                "同意，老夫就同你过两招。\n");

    if (!this_object()->query_temp("weapon"))
        {
            weapon=present( "sword", environment(this_object()) );
            if (weapon)
                    this_object()->wield(weapon->query("id"));
            else
                    carry_object(WEAPON_DIR"bamboo_sword")->wield();
            write("风青扬从身后抽出一把竹剑握在手中。\n");
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
            tell_object(me, "\n你取消了和风青扬的比试。\n");
            return;
        }

    if (ob->query_temp("unconcious"))
        {
            tell_object(me, "\n看来风青扬不能继续和你比试了。\n");
            return;
        }

    if ( (!me->is_fighting() ||
             !ob->is_fighting()) &&
             flag<3 )
        {
            ob->remove_all_enemy();
            me->remove_all_enemy();
            tell_object(me, "\n风青扬收剑说道：看来"+RANK_D->query_respect(this_player())+
          "还是没有准备好，还是等准备好了之后再说吧。\n");
            remove_call_out("do_perform_player");
            return;
        }

    if ( !ob->query_temp("weapon") )
        {
            ob->remove_all_enemy();
            me->remove_all_enemy();
            tell_object(me, "\n风青扬收招扬说道："+
          RANK_D->query_respect(this_player())+
          "既然来学习『御剑式』，就要诚心战斗，不要戏弄老夫！\n");
            remove_call_out("do_perform_player");
            me->delete_temp("asked_yujian_fight");
            return;
        }

    if (flag == -1)
        {
            tell_object(me, HIY"\n风青扬说道："+
          RANK_D->query_respect(this_player())+
          "小心，老夫要出『御剑式』了！\n\n"NOR);
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
            tell_object(me, "\n风青扬向后一纵，将剑收回。\n");
            call_out("do_perform_player", 2, 3);
            return;
        }

    if (flag == 3)

        {
            tell_object(me, WHT"\n
风青扬收剑说道：好！果然江湖辈有人才出！老夫就将『御剑式』的口诀传授与你，
希望你以后行走江湖要行侠仗义，切记不能乱杀无辜，给华山派若来事端。\n"NOR);
            call_out("do_perform_player", 3, 4);
            return;
        }

    if (flag == 4)
        {
            tell_object(me, WHT"\n风青扬将独孤九剑『御剑式』的口诀传授给你。\n\n"NOR);
            call_out("do_perform_player", 4, 5);
            return;
        }

    if (flag == 5)
        {
            tell_object(me, HIC"你终于领悟了『御剑式』！\n\n"NOR);
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
    return "你的『御剑式』和『荡剑式』已经被撤销了，请重新领悟。\n";
}
