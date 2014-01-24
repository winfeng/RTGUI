#include <rtthread.h>
#include <rtgui/rtgui.h>
#include <rtgui/rtgui_app.h>
#include <rtgui/widgets/container.h>
#include <rtgui/widgets/window.h>
#include <rtgui/dc.h>
#include <rtgui/font.h>
#include <rtgui/widgets/button.h>
#include <rtgui/image.h>
#include <rtgui/widgets/edit.h>

#define  LOGO_PATH "/logo/"
static	struct rtgui_edit *edit;
struct rtgui_win *win1;
	rtgui_win_t *msgwin;
void WarnWindowCreat(const char *title, rtgui_win_t **thiswin);



extern struct edit_line *rtgui_edit_get_line_by_index(struct rtgui_edit *, rt_uint32_t );
static void button_click(struct rtgui_object *object, struct rtgui_event *event)
{
	struct edit_line *line = rtgui_edit_get_line_by_index(edit,rtgui_edit_get_current_point(edit).y);

    rtgui_edit_append_line(edit,"11111111111");
    rtgui_edit_insert_line(edit,line,"2222222222222");
	rtgui_edit_delete_line(edit,line);
	rtgui_widget_update(RTGUI_WIDGET(edit));
}

static void button1_click(struct rtgui_object *object, struct rtgui_event *event)
{
	struct edit_line *line = rtgui_edit_get_line_by_index(edit,rtgui_edit_get_current_point(edit).y);

    rtgui_edit_append_line(edit,"11111111111");
    rtgui_edit_insert_line(edit,line,"2222222222222");
    rtgui_edit_delete_line(edit,line);
	rtgui_edit_set_text(edit,
                        "1一二三四五六七八九十甲乙丙丁戊己庚辛壬癸子丑寅卯辰巳午未申酉戌亥一\n"
                        "一2二三四五六七八九十甲乙丙丁戊己庚辛壬癸子丑寅卯辰巳午\n"
                        "3一二三四五六七八九十甲乙丙丁戊己庚辛壬癸子丑寅卯12345678辰巳午未申酉戌亥一二三四五\n"
                        "一4二三四五六七八九十甲乙丙丁戊己庚辛壬癸子丑寅卯辰巳午未申酉戌亥一二三\n"
                        "1234567890123456789012345678901234567890四五六12345678甲乙丙丁戊己庚辛\n"
                        "5一二三四五六七八九十甲abc\n"
                        "一6二三四五六七八九十甲乙丙丁戊己庚辛壬癸子丑寅\n"
                        "7一二三四五六assault甲乙丙丁戊己庚辛\n"
                        "一8二三\n"
                        "9一二三四五六12345678甲乙丙丁戊己庚辛\n");
	rtgui_edit_append_line(edit,"11111111111");
	rtgui_widget_update(RTGUI_WIDGET(edit));
}
static void button2_click(struct rtgui_object *object, struct rtgui_event *event)
{
	struct edit_line *line = rtgui_edit_get_line_by_index(edit,rtgui_edit_get_current_point(edit).y);

	rtgui_edit_append_line(edit,"11111111111");
	rtgui_edit_insert_line(edit,line,"2222222222222");
	rtgui_edit_set_text(edit,"");
	rtgui_edit_append_line(edit,"11111111111");
	rtgui_edit_delete_line(edit,line);
	rtgui_widget_update(RTGUI_WIDGET(edit));
}


void edit_print_test(void)
{
#define P rt_kprintf
    P("1, 在空白状态下点击 edit 控件，应当在第一行第一列显示光标。\n");
    P("2, 输入字符正常\n");
    P("3, 按住 SHIFT 之后，输入大写字符正常\n");
    P("4, 按 CAPSLOCK，进入大写模式。之后输入大写字符正常\n");
    P("5, 再按 CAPSLOCK，推出大写模式。之后输入小写字符正常\n");
#undef P
}

/**
* @function name :win1_ui_init()
* @param : void
* @return : void
* @note :the init function of win1
**/
void win1_ui_init(void)
{
    //struct rtgui_win *input_win;
    rtgui_rect_t rect = {0, 0, 480, 272};
	rtgui_rect_t input_rect={0,150,480,272};

	struct rtgui_button *button,*button1,*button2;

//win1 Create
    {
		win1 = rtgui_win_create(RT_NULL, "win1",&rect, RTGUI_WIN_STYLE_MAINWIN | RTGUI_WIN_STYLE_NO_BORDER | RTGUI_WIN_STYLE_NO_TITLE);
		//input_win=rtgui_win_create(win1,"input",&input_rect,RTGUI_WIN_STYLE_ONTOP | RTGUI_WIN_STYLE_NO_BORDER | RTGUI_WIN_STYLE_NO_TITLE);
		//rtgui_object_set_event_handler(RTGUI_OBJECT(input_win), input_event_handler);
		//RTGUI_WIDGET_BACKGROUND(win1)=RTGUI_RGB(0,0,0);
    }
	{
		button=rtgui_button_create("abc");
		rect.x1=50;
		rect.x2=rect.x1+50;
		rect.y1=240;
		rect.y2=rect.y1+20;
		rtgui_widget_set_rect(RTGUI_WIDGET(button),&rect);
		rtgui_button_set_onbutton(button,button_click);
		RTGUI_WIDGET_FLAG(button)&=~RTGUI_WIDGET_FLAG_FOCUSABLE;
		rtgui_container_add_child(RTGUI_CONTAINER(win1),RTGUI_WIDGET(button));

	}
		{
		button1=rtgui_button_create("abc");
		rect.x1=150;
		rect.x2=rect.x1+50;
		rect.y1=240;
		rect.y2=rect.y1+20;
		rtgui_widget_set_rect(RTGUI_WIDGET(button1),&rect);
		rtgui_button_set_onbutton(button1,button1_click);
		RTGUI_WIDGET_FLAG(button1)&=~RTGUI_WIDGET_FLAG_FOCUSABLE;
		
		rtgui_container_add_child(RTGUI_CONTAINER(win1),RTGUI_WIDGET(button1));

	}
	  {
		button2=rtgui_button_create("abc");
		rect.x1=250;
		rect.x2=rect.x1+50;
		rect.y1=240;
		rect.y2=rect.y1+20;
		rtgui_widget_set_rect(RTGUI_WIDGET(button2),&rect);
		rtgui_button_set_onbutton(button2,button2_click);
		RTGUI_WIDGET_FLAG(button2)&=~RTGUI_WIDGET_FLAG_FOCUSABLE;
		rtgui_container_add_child(RTGUI_CONTAINER(win1),RTGUI_WIDGET(button2));

	}
	{
		edit=rtgui_edit_create(RTGUI_CONTAINER(win1),10,10,400,200);
	
	}
	//rtgui_widget_focus(RTGUI_WIDGET(button1));



    rtgui_win_show(win1, RT_TRUE);
}
