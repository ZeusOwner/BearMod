package com.bearmod;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Process;
import android.provider.Settings;
import android.text.Html;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;
import android.graphics.drawable.GradientDrawable;
import android.graphics.Color;
import android.widget.TextView;
import java.security.acl.Group;
import java.util.Objects;
import java.util.concurrent.atomic.AtomicBoolean;
import androidx.annotation.NonNull;

import android.view.Gravity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.graphics.drawable.Drawable;
import android.util.TypedValue;
import android.graphics.Rect;
import android.app.Activity;


public class Launcher {

    // Thread safety and crash prevention
    private static final AtomicBoolean isInitializing = new AtomicBoolean(false);
    private static final Object lockObject = new Object();
    private static volatile SharedPreferences gifs;

    public static native String LoginNameNrg();
    public static native String Pleaselog();
    public static native String KeyAdd();
    public static native String Login();
    public static native String Cancel();
    public static native String Error();
    public static native String Pleasecheck();
    public static native String Ok();
    public static native String Loging();
    
    static{
        try {
            System.loadLibrary("bearmod");
        } catch (UnsatisfiedLinkError | Exception e) {
            e.printStackTrace();
        }
    }
    
    void hideesp() {
        try {
            Floating.hideesp();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void stopHideesp() {
        try {
            Floating.stopHideesp();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void Init(Object object) {
        try {
            if (object == null) {
                return;
            }
            
            if (!isInitializing.compareAndSet(false, true)) {
                return; // Already initializing
            }
            
            synchronized (lockObject) {
                final Context context = (Context) object;
                Activity m_Activity = (Activity) object;

                if (context == null) {
                    isInitializing.set(false);
                    return;
                }

                Init(context);

                // Check overlay permission safely
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                    if (!Settings.canDrawOverlays(context)) {
                        try {
                            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, 
                                Uri.parse("package:" + context.getPackageName()));
                            m_Activity.startActivity(intent);
                        } catch (Exception e) {
                            e.printStackTrace();
                            Toast.makeText(context, "Please grant overlay permission manually", Toast.LENGTH_LONG).show();
                        }
                    }
                }

                try {
                    gifs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
                } catch (Exception e) {
                    e.printStackTrace();
                    isInitializing.set(false);
                    return;
                }

                if (gifs == null || !gifs.contains("USER_KEY")) {
                    showLoginDialog(context);
                } else {
                    String userKey = gifs.getString("USER_KEY", null);
                    if (userKey != null && !userKey.isEmpty()) {
                        Login(context, userKey);
                    } else {
                        showLoginDialog(context);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            isInitializing.set(false);
        }
    }

    private static void showLoginDialog(Context context) {
        try {
            if (context == null) return;
            
            final SharedPreferences sharedPreferences = context.getSharedPreferences("SavePref", 0);
            String string = sharedPreferences.getString("User", "");
            String string2 = sharedPreferences.getString("Pass", "");

            //Create LinearLayout
            LinearLayout linearLayout = new LinearLayout(context);
            linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            linearLayout.setOrientation(LinearLayout.VERTICAL);
            
            GradientDrawable gradientdrawable = new GradientDrawable();
            gradientdrawable.setCornerRadius(30);
            gradientdrawable.setColor(Color.parseColor("#FFF1F1F1"));
            gradientdrawable.setStroke(0, Color.parseColor("#32cb00"));
            linearLayout.setBackground(gradientdrawable);

            TextView txt = new TextView(context);
            txt.setGravity(Gravity.CENTER);
            try {
                txt.setText(LoginNameNrg());
            } catch (Exception e) {
                txt.setText("Login");
            }
            txt.setTextColor(0xFF181818);
            txt.setBackgroundColor(Color.TRANSPARENT);
            txt.setTextSize(19);
            txt.setPadding(1,1,1,1);

            TextView txt1 = new TextView(context);
            txt1.setGravity(Gravity.CENTER);
            try {
                txt1.setText(Pleaselog());
            } catch (Exception e) {
                txt1.setText("Please log in");
            }
            txt1.setTextColor(0xFF151515);
            txt1.setBackgroundColor(Color.TRANSPARENT);
            txt1.setTextSize(9);

            final EditText editTextUser = new EditText(context);
            editTextUser.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            editTextUser.setTextColor(Color.parseColor("#000000bb"));
            
            try {
                editTextUser.setHint(KeyAdd());
            } catch (Exception e) {
                editTextUser.setHint("Enter Key");
            }
            
            editTextUser.setGravity(Gravity.CENTER);
            editTextUser.setTextColor(Color.parseColor("#000000"));
            editTextUser.setBackgroundColor(Color.parseColor("#000000"));
            editTextUser.setHintTextColor(Color.parseColor("#000000"));

            // Create stroke drawable
            GradientDrawable strokeDrawable = new GradientDrawable();
            strokeDrawable.setShape(GradientDrawable.RECTANGLE);
            strokeDrawable.setColor(Color.parseColor("#fafafa"));
            strokeDrawable.setCornerRadius(20);
            strokeDrawable.setStroke(30, Color.TRANSPARENT);
            editTextUser.setBackground(strokeDrawable);

            LinearLayout ln3 = new LinearLayout(context);
            ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, 1));
            ln3.setOrientation(LinearLayout.HORIZONTAL);
            ln3.setGravity(Gravity.CENTER);
            ln3.setBackgroundColor(Color.GRAY);

            LinearLayout ln2 = new LinearLayout(context);
            ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
            ln2.setOrientation(LinearLayout.HORIZONTAL);
            ln2.setGravity(Gravity.CENTER);

            Button button = new Button(context);
            button.setTextColor(Color.BLUE);
            try {
                button.setText(Login());
            } catch (Exception e) {
                button.setText("Login");
            }
            button.setBackgroundColor(Color.TRANSPARENT);

            LinearLayout ln4 = new LinearLayout(context);
            ln4.setLayoutParams(new LinearLayout.LayoutParams(1, LinearLayout.LayoutParams.MATCH_PARENT));
            ln4.setOrientation(LinearLayout.HORIZONTAL);
            ln4.setGravity(Gravity.CENTER);
            ln4.setBackgroundColor(Color.GRAY);

            Button button2 = new Button(context);
            button2.setTextColor(Color.BLUE);
            try {
                button2.setText(Cancel());
            } catch (Exception e) {
                button2.setText("Cancel");
            }
            button2.setBackgroundColor(Color.TRANSPARENT);

            linearLayout.addView(txt);
            linearLayout.addView(txt1);
            linearLayout.addView(editTextUser);
            linearLayout.addView(ln3);
            ln2.addView(button2);
            ln2.addView(ln4);
            ln2.addView(button);
            linearLayout.addView(ln2);

            //Create alertdialog
            final Dialog builder = new Dialog(context);
            builder.setCancelable(false);
            builder.setContentView(linearLayout);
            
            try {
                Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);
            } catch (Exception e) {
                e.printStackTrace();
            }

            button.setOnClickListener(view -> {
                try {
                    String userKey = editTextUser.getText().toString().trim();
                    if (!userKey.isEmpty()) {
                        Login(context, userKey);
                        builder.dismiss();
                    } else {
                        Toast.makeText(context, "Please enter a valid key", Toast.LENGTH_SHORT).show();
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
            
            button2.setOnClickListener(view -> {
                try {
                    builder.dismiss();
                    Process.killProcess(Process.myPid());
                } catch (Exception e) {
                    e.printStackTrace();
                    System.exit(0);
                }
            });
            
            builder.show();
        } catch (Exception e) {
            e.printStackTrace();
            isInitializing.set(false);
        }
    }

    private static void Login(final Context context, final String userKey) {
        try {
            if (context == null || userKey == null || userKey.trim().isEmpty()) {
                isInitializing.set(false);
                return;
            }
            
            LinearLayout linearLayout = new LinearLayout(context);
            linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            linearLayout.setOrientation(LinearLayout.VERTICAL);

            GradientDrawable gradientdrawable = new GradientDrawable();
            gradientdrawable.setCornerRadius(20);
            gradientdrawable.setColor(Color.parseColor("#FFF1F1F1"));
            gradientdrawable.setStroke(0, Color.parseColor("#32cb00"));
            linearLayout.setBackground(gradientdrawable);

            TextView txt = new TextView(context);
            txt.setGravity(Gravity.CENTER);
            try {
                txt.setText(Loging());
            } catch (Exception e) {
                txt.setText("Logging in...");
            }
            txt.setTextColor(0xFF181818);
            txt.setBackgroundColor(Color.TRANSPARENT);
            txt.setTextSize(20);

            linearLayout.addView(txt);

            final Dialog builder = new Dialog(context);
            builder.setCancelable(false);
            builder.setContentView(linearLayout);
            
            try {
                Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);
            } catch (Exception e) {
                e.printStackTrace();
            }
            
            builder.show();

            @SuppressLint("HandlerLeak") 
            final Handler sagen = new Handler(Looper.getMainLooper()) {
                @Override
                public void handleMessage(@NonNull Message ems) {
                    try {
                        if (ems.what == 0) {
                            // Success
                            try {
                                Intent i = new Intent(context.getApplicationContext(), Floating.class);
                                context.startService(i);
                                isInitializing.set(false);
                            } catch (Exception e) {
                                e.printStackTrace();
                                showErrorDialog(context, "Failed to start service");
                            }
                        } else if (ems.what == 1) {
                            // Error
                            showErrorDialog(context, ems.obj != null ? ems.obj.toString() : "Unknown error");
                        }
                        
                        try {
                            builder.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                        isInitializing.set(false);
                    }
                }
            };

            // Perform login in background thread
            new Thread(() -> {
                try {
                    String result = Check(context, userKey);
                    if ("OK".equals(result)) {
                        if (gifs != null) {
                            gifs.edit().putString("USER_KEY", userKey).apply();
                        }
                        sagen.sendEmptyMessage(0);
                    } else {
                        if (gifs != null) {
                            gifs.edit().clear().apply();
                        }
                        
                        Message ems = new Message();
                        ems.what = 1;
                        ems.obj = result != null ? result : "Authentication failed";
                        sagen.sendMessage(ems);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    
                    Message ems = new Message();
                    ems.what = 1;
                    ems.obj = "Network error: " + e.getMessage();
                    sagen.sendMessage(ems);
                }
            }).start();
        } catch (Exception e) {
            e.printStackTrace();
            isInitializing.set(false);
        }
    }

    private static void showErrorDialog(Context context, String errorMessage) {
        try {
            if (context == null) return;
            
            LinearLayout linearLayout = new LinearLayout(context);
            linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            linearLayout.setOrientation(LinearLayout.VERTICAL);

            GradientDrawable gradientdrawable = new GradientDrawable();
            gradientdrawable.setCornerRadius(30);
            gradientdrawable.setColor(Color.parseColor("#FFF1F1F1"));
            gradientdrawable.setStroke(0, Color.parseColor("#32cb00"));
            linearLayout.setBackground(gradientdrawable);

            TextView txt = new TextView(context);
            txt.setGravity(Gravity.CENTER);
            try {
                txt.setText(Error());
            } catch (Exception e) {
                txt.setText("Error");
            }
            txt.setTextColor(0xFF181818);
            txt.setBackgroundColor(Color.TRANSPARENT);
            txt.setTextSize(20);

            TextView txt1 = new TextView(context);
            txt1.setGravity(Gravity.CENTER);
            try {
                txt1.setText(Pleasecheck());
            } catch (Exception e) {
                txt1.setText("Please check your key");
            }
            txt1.setTextColor(0xFF595959);
            txt1.setBackgroundColor(Color.TRANSPARENT);
            txt1.setTextSize(13);

            final TextView infoText = new TextView(context);
            infoText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            infoText.setGravity(Gravity.CENTER);
            infoText.setBackgroundColor(Color.TRANSPARENT);
            infoText.setText(errorMessage != null ? errorMessage : "Unknown error");

            LinearLayout ln3 = new LinearLayout(context);
            ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, 1));
            ln3.setOrientation(LinearLayout.HORIZONTAL);
            ln3.setGravity(Gravity.CENTER);
            ln3.setBackgroundColor(Color.GRAY);

            LinearLayout ln2 = new LinearLayout(context);
            ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
            ln2.setOrientation(LinearLayout.HORIZONTAL);
            ln2.setGravity(Gravity.CENTER);

            Button button = new Button(context);
            button.setTextColor(Color.BLUE);
            try {
                button.setText(Ok());
            } catch (Exception e) {
                button.setText("OK");
            }
            button.setBackgroundColor(Color.TRANSPARENT);

            linearLayout.addView(txt);
            linearLayout.addView(txt1);
            linearLayout.addView(infoText);
            linearLayout.addView(ln3);
            ln2.addView(button);
            linearLayout.addView(ln2);

            final Dialog builder = new Dialog(context);
            builder.setCancelable(false);
            builder.setContentView(linearLayout);
            
            try {
                Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);
            } catch (Exception e) {
                e.printStackTrace();
            }

            button.setOnClickListener(view -> {
                try {
                    builder.dismiss();
                    isInitializing.set(false);
                    System.exit(0);
                } catch (Exception e) {
                    e.printStackTrace();
                    Process.killProcess(Process.myPid());
                }
            });

            builder.show();
        } catch (Exception e) {
            e.printStackTrace();
            isInitializing.set(false);
        }
    }
    
    private static native void Init(Context mContext);
    private static native String Check(Context mContext, String userKey);
}


